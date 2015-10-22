package com.example.movielist.networkops;

import android.os.AsyncTask;

import com.example.movielist.settings.Constants;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLEncoder;

/**
 * Created by asmita on 26/9/15.
 */
public class RetrieveInformation extends AsyncTask<String, Void, String> {

    @Override
    protected String doInBackground(String... params) {
        try {
            String query = params[0];
            URL url = new URL(Constants.OMDB_URL + "/?t=" + URLEncoder.encode(query, "UTF-8") + "&plot=short&r=json");
            HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();
            BufferedReader reader = new BufferedReader(new InputStreamReader(urlConnection.getInputStream()));
            String line;
            String response = new String();
            while ((line = reader.readLine()) != null) {
                response += line;
            }
            reader.close();

            return response;


        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    protected void onPostExecute(String info) {

    }
}
