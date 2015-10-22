package com.example.movielist.activities;

import android.app.SearchManager;
import android.app.SearchableInfo;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SearchView;
import android.widget.Toast;

import com.example.movielist.R;
import com.example.movielist.adapters.MovieListAdapter;
import com.example.movielist.database.Movie;
import com.example.movielist.database.MyDBHandler;
import com.example.movielist.settings.Constants;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLEncoder;
import java.util.ArrayList;

public class HomeActivity extends AppCompatActivity {

    MyDBHandler dbHandler;

    Handler handler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            super.handleMessage(msg);
            final String response = msg.getData().getString("response");

            if (response != null) {
                try {
                    JSONObject json = (JSONObject) new JSONParser().parse(response);
                    if (json.containsKey("Title")) {
                        Movie movie = new Movie();
                        movie.set_name((String) json.get("Title"));
//                        Toast.makeText(getBaseContext(), "Response: " + movie.get_name(), Toast.LENGTH_SHORT).show();

                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                Intent intent = new Intent(HomeActivity.this, MovieDetailsActivity.class);
                                intent.putExtra("details", response);
                                startActivity(intent);
                            }
                        });



                    }
                    else {
                        Toast.makeText(getBaseContext(), "Error", Toast.LENGTH_SHORT).show();
                    }
                } catch (ParseException e) {
                    e.printStackTrace();
                }

            }
            else {
                Toast.makeText(getBaseContext(), "Problem!", Toast.LENGTH_SHORT).show();
            }

        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);
        handleIntent(getIntent());


        // populating the movie list from db

        dbHandler = new MyDBHandler(this, null, null, 1);

        ArrayList <Movie> movieList = getMovieList();

        final ListView listView = (ListView) findViewById(R.id.movie_list);
        listView.setAdapter(new MovieListAdapter(this, movieList));
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Movie movie = (Movie) listView.getItemAtPosition(position);
                // TODO: Call OMDB API here and start MovieActivity
                Toast.makeText(HomeActivity.this, movie.get_name(), Toast.LENGTH_SHORT).show();
            }
        });
    }

    @Override
    protected void onNewIntent(Intent intent) {
        setIntent(intent);
        handleIntent(intent);
    }

    private void handleIntent(Intent intent) {
        if (Intent.ACTION_SEARCH.equals(intent.getAction())) {
            String query = intent.getStringExtra(SearchManager.QUERY);
            searchMovie(query);
//            String movie = searchMovie(query);
//            Toast.makeText(this, "Query: " + movie, Toast.LENGTH_SHORT).show();
        }
    }


    private void searchMovie(final String query) {
        // Call OMDB API to get movie with the name = query
        final String[] response = {new String()};

        Runnable r = new Runnable() {
            @Override
            public void run() {
                try {
                    URL url = new URL(Constants.OMDB_URL + "/?t=" + URLEncoder.encode(query, "UTF-8") + "&plot=short&r=json");
                    HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
                    BufferedReader reader = new BufferedReader(new InputStreamReader(urlConnection.getInputStream()));
                    String line;

                    while ((line = reader.readLine()) != null) {
                        response[0] += line;
                    }
                    reader.close();
                    Bundle bundle = new Bundle();
                    bundle.putString("response", response[0]);
                    Message message =  new Message();
                    message.setData(bundle);
                    handler.sendMessage(message);

                } catch (MalformedURLException e) {
                    e.printStackTrace();
                } catch (UnsupportedEncodingException e) {
                    e.printStackTrace();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        };

        Thread thread = new Thread(r);
        thread.start();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_home, menu);

        SearchManager searchManager = (SearchManager) getSystemService(Context.SEARCH_SERVICE);
        final SearchView searchView = (SearchView) findViewById(R.id.searchView);
        SearchableInfo searchableInfo = searchManager.getSearchableInfo(getComponentName());
        searchView.setSearchableInfo(searchableInfo);

        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    private ArrayList<Movie> getMovieList() {
        ArrayList <Movie> movieList = dbHandler.getMovieList();
        if (movieList == null)
            return new ArrayList<Movie>();
        return movieList;
    }
}
