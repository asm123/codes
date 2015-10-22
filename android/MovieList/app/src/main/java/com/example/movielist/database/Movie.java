package com.example.movielist.database;

public class Movie {
    private int _id;
    private String _name;
    private Boolean _watched;

    public Movie() {
    }

    public Movie(String _name) {
        this._name = _name;
    }

    public int get_id() {
        return _id;
    }

    public void set_id(int _id) {
        this._id = _id;
    }

    public String get_name() {
        return _name;
    }

    public void set_name(String _name) {
        this._name = _name;
    }

    public Boolean get_watched() {
        return _watched;
    }

    public void set_watched(Boolean _watched) {
        this._watched = _watched;
    }
}
