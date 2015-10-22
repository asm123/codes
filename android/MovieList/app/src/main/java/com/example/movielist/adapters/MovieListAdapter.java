package com.example.movielist.adapters;


import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.example.movielist.R;
import com.example.movielist.database.Movie;

import java.util.ArrayList;

public class MovieListAdapter extends BaseAdapter {

    private ArrayList movieList;
    private LayoutInflater layoutInflater;

    public MovieListAdapter(Context context, ArrayList movieList) {
        this.movieList = movieList;
        layoutInflater = LayoutInflater.from(context);
    }

    @Override
    public int getCount() {
        return movieList.size();
    }

    @Override
    public Object getItem(int position) {
        return movieList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder holder;
        if (convertView == null) {
            convertView = layoutInflater.inflate(R.layout.list_row_view, null);
            holder = new ViewHolder();
            holder.titleView = (TextView) convertView.findViewById(R.id.title);
            convertView.setTag(holder);
        }
        else {
            holder = (ViewHolder) convertView.getTag();
        }
        Movie movie = (Movie) movieList.get(position);
        holder.titleView.setText(movie.get_name());
        return convertView;
    }

    static class ViewHolder {
        TextView titleView;
    }
}
