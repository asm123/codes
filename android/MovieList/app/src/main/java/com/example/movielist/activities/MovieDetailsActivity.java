package com.example.movielist.activities;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.movielist.R;
import com.example.movielist.database.Movie;
import com.example.movielist.database.MyDBHandler;
import com.example.movielist.utils.MovieDetails;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.InputStream;

public class MovieDetailsActivity extends AppCompatActivity {

    MyDBHandler dbHandler;
    MovieDetails movieDetails;
    FloatingActionButton fab;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_movie_details);

        Intent intent = getIntent();
        String response = intent.getStringExtra("details");
        movieDetails = getMovieDetails(response);

        dbHandler = new MyDBHandler(this, null, null, 1);

        ((TextView) findViewById(R.id.movie_title)).setText(movieDetails.getTitle().trim());
        ((TextView) findViewById(R.id.genre)).setText(movieDetails.getGenres());
        ((TextView) findViewById(R.id.metascore)).setText(String.valueOf(movieDetails.getMetascore()));
        ((TextView) findViewById(R.id.rating)).setText(String.valueOf(movieDetails.getRating()));
        ((TextView) findViewById(R.id.movie_plot)).setText(movieDetails.getPlot());
        ((TextView) findViewById(R.id.director)).setText(movieDetails.getDirector());
        ((TextView) findViewById(R.id.writer)).setText(movieDetails.getWriter());
        ((TextView) findViewById(R.id.cast)).setText(movieDetails.getCast());

        new DownloadImageTask((ImageView) findViewById(R.id.poster))
            .execute(movieDetails.getImageUrl());

        fab = (FloatingActionButton) findViewById(R.id.add_to_wishlist);
        if (dbHandler.isInWishlist(movieDetails.getTitle())) {
            fab.setImageResource(R.drawable.ic_watched);
        }
        else {
            fab.setImageResource(R.drawable.ic_add);
        }
    }

    public void addToWishlist(View view) {
        String title = movieDetails.getTitle();
        if (!dbHandler.isInWishlist(title)) {
            Movie movie = new Movie();
            movie.set_name(title);
            movie.set_watched(false);
            dbHandler.addMovie(movie);
            fab.setImageResource(R.drawable.ic_watched);
            Toast.makeText(MovieDetailsActivity.this, "Added " + title + " to watchlist!", Toast.LENGTH_SHORT).show();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_movie_details, menu);
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

    private MovieDetails getMovieDetails(String response) {
        MovieDetails movieDetails = new MovieDetails();

        if (response != null) {
            try {
                JSONObject json = (JSONObject) new JSONParser().parse(response);
                movieDetails.setTitle((String) json.get("Title"));
                if (json.containsKey("Poster"))
                    movieDetails.setImageUrl((String) json.get("Poster"));
                if (json.containsKey("Genre")) {
                    movieDetails.setGenres((String) json.get("Genre"));
                }
                if (json.containsKey("Metascore"))
                    movieDetails.setMetascore(Integer.parseInt((String) json.get("Metascore")));
                if (json.containsKey("imdbRating"))
                    movieDetails.setRating(Double.parseDouble((String) json.get("imdbRating")));
                if (json.containsKey("Plot"))
                    movieDetails.setPlot((String) json.get("Plot"));
                if (json.containsKey("Director"))
                    movieDetails.setDirector((String) json.get("Director"));
                if (json.containsKey("Writer"))
                    movieDetails.setWriter((String) json.get("Writer"));
                if (json.containsKey("Actors"))
                    movieDetails.setCast((String) json.get("Actors"));
            }
            catch (ParseException e) {
                e.printStackTrace();
            }
        }

        return movieDetails;
    }
}

class DownloadImageTask extends AsyncTask<String, Void, Bitmap> {
    ImageView bmImage;

    public DownloadImageTask(ImageView bmImage) {
        this.bmImage = bmImage;
    }

    protected Bitmap doInBackground(String... urls) {
        String urldisplay = urls[0];
        Bitmap mIcon11 = null;
        try {
            InputStream in = new java.net.URL(urldisplay).openStream();
            mIcon11 = BitmapFactory.decodeStream(in);
        } catch (Exception e) {
            Log.e("Error", e.getMessage());
            e.printStackTrace();
        }
        return mIcon11;
    }

    protected void onPostExecute(Bitmap result) {
        bmImage.setImageBitmap(result);
    }
}
