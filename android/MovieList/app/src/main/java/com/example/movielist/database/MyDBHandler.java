package com.example.movielist.database;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;

public class MyDBHandler extends SQLiteOpenHelper {

    private static final int DATABASE_VERSION = 1;
    private static final String DATABASE_NAME = "movielist.db";

    public static final String TABLE_MOVIELIST = "movielist";

    public static final String COLUMN_ID = "_id";
    public static final String COLUMN_NAME = "_name";
    public static final String COLUMN_WATCHED = "_watched";

    public MyDBHandler(Context context, String name, SQLiteDatabase.CursorFactory factory, int version) {
        super(context, DATABASE_NAME, factory, DATABASE_VERSION);
    }


    @Override
    public void onCreate(SQLiteDatabase db) {
        String query = "CREATE TABLE " + TABLE_MOVIELIST + "("
                + COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, "
                + COLUMN_NAME + " TEXT, "
                + COLUMN_WATCHED + " INTEGER DEFAULT 0"
                + ");";
        db.execSQL(query);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_MOVIELIST);
        onCreate(db);
    }

    // Add a new movie to the watchlist
    public void addMovie(Movie movie) {
        ContentValues values = new ContentValues();
        values.put(COLUMN_NAME, movie.get_name());
        values.put(COLUMN_WATCHED, (movie.get_watched()) ? true : false);
        SQLiteDatabase db = getWritableDatabase();
        db.insert(TABLE_MOVIELIST, null, values);
        db.close();
    }

    // Delete a movie from the watchlist
    public void deleteMovie(Movie movie) {
        SQLiteDatabase db = getWritableDatabase();
        db.execSQL("DELETE FROM " + TABLE_MOVIELIST + " WHERE " + COLUMN_NAME +
                "=\"" + movie.get_name() + "\";");
        db.close();
    }

    // Get all the movies from the database
    public ArrayList<Movie> getMovieList() {

        ArrayList <Movie> movies = new ArrayList<>();

        SQLiteDatabase db = getWritableDatabase();
        String query = "SELECT * FROM " + TABLE_MOVIELIST + " WHERE 1";

        Cursor cursor = db.rawQuery(query, null);
        cursor.moveToFirst();
        while(!cursor.isAfterLast()) {
            if(cursor.getString(cursor.getColumnIndex(COLUMN_NAME)) != null) {
                Movie movie = new Movie();
                movie.set_id(cursor.getInt(cursor.getColumnIndex(COLUMN_ID)));
                movie.set_name(cursor.getString(cursor.getColumnIndex(COLUMN_NAME)));
                movie.set_watched(cursor.getInt((cursor.getColumnIndex(COLUMN_WATCHED))) == 0 ? true : false);
                movies.add(movie);
            }
        }
        db.close();
        return movies;
    }

    // Set a movie as watched or unwatched
    public void setWatched(Movie movie, Boolean watched) {
        String strFilter = COLUMN_ID + "=" + movie.get_id();

        ContentValues values = new ContentValues();
        values.put(COLUMN_NAME, movie.get_name());
        values.put(COLUMN_WATCHED, watched);
        SQLiteDatabase db = getWritableDatabase();

        db.update(TABLE_MOVIELIST, values, strFilter, null);
        db.close();
    }

    // Check whether a movie is watched
    public Boolean isWatched(String title) {
        Boolean watched = false;
        SQLiteDatabase db = getWritableDatabase();
        String query = "SELECT * FROM " + TABLE_MOVIELIST + " WHERE " + COLUMN_NAME + "=\"" + title + "\";";
        Cursor cursor = db.rawQuery(query, null);
        cursor.moveToFirst();
        while(!cursor.isAfterLast()) {
            if(cursor.getString(cursor.getColumnIndex(COLUMN_NAME)) != null) {
                watched = cursor.getInt((cursor.getColumnIndex(COLUMN_WATCHED))) == 0 ? true : false;
                break;
            }
        }
        db.close();
        return watched;
    }

    // Check whether movie is already in wishlist
    public Boolean isInWishlist(String title) {
        Boolean inWishlist = false;
        SQLiteDatabase db = getWritableDatabase();
        String query = "SELECT * FROM " + TABLE_MOVIELIST + " WHERE " + COLUMN_NAME + "=\"" + title + "\";";
        Cursor cursor = db.rawQuery(query, null);
        cursor.moveToFirst();
        while(!cursor.isAfterLast()) {
            if(cursor.getString(cursor.getColumnIndex(COLUMN_NAME)) != null) {
                inWishlist = cursor.getInt((cursor.getColumnIndex(COLUMN_WATCHED))) == 0 ? true : false;
                break;
            }
        }
        db.close();
        return inWishlist;
    }
}
