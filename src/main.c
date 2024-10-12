#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "buttons.h"

GtkWidget *entry;
GtkWidget *grid;
GtkWidget *button_clear;
GtkWidget *button_del;
GtkWidget *button_puis;
GtkWidget *button_dot;
GtkWidget *button_add;
GtkWidget *button_sub;
GtkWidget *button_multi;
GtkWidget *button_div;
GtkWidget *button_eq;
GtkWidget *button_0;
GtkWidget *button_1;
GtkWidget *button_2;
GtkWidget *button_3;
GtkWidget *button_4;
GtkWidget *button_5;
GtkWidget *button_6;
GtkWidget *button_7;
GtkWidget *button_8;
GtkWidget *button_9;

static void print_hello (GtkWidget *widget, gpointer   data)
{
    g_print ("Hello World\n");
}

static void activate (GtkApplication *app, gpointer user_data)
{

    GtkWidget *window;

    /* create a new window, and set its title */
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Calculator");

    /* Here we construct the container that is going pack our buttons */
    grid = gtk_grid_new ();

    /* Pack the container in the window */
    gtk_window_set_child (GTK_WINDOW (window), grid);

    entry = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 9, 1);
    gtk_widget_set_size_request(entry, 240, 70);
    
    button_clear = gtk_button_new_with_mnemonic("C");
	gtk_grid_attach(GTK_GRID(grid), button_clear, 0, 1, 1, 1);
	gtk_widget_set_size_request(button_clear, 60, 60);

    button_del = gtk_button_new_with_mnemonic("del");
	gtk_grid_attach(GTK_GRID(grid), button_del, 1, 1, 1, 1);
	gtk_widget_set_size_request(button_del, 60, 60);

    button_puis = gtk_button_new_with_mnemonic("%");
	gtk_grid_attach(GTK_GRID(grid), button_puis, 2, 1, 1, 1);
	gtk_widget_set_size_request(button_puis, 60, 60);

    /* Op buttons */
    button_div = gtk_button_new_with_mnemonic("/");
	gtk_grid_attach(GTK_GRID(grid), button_div, 3, 1, 1, 1);
	gtk_widget_set_size_request(button_div, 60, 60);

    button_multi = gtk_button_new_with_mnemonic("x");
	gtk_grid_attach(GTK_GRID(grid), button_multi, 3, 2, 1, 1);
	gtk_widget_set_size_request(button_multi, 60, 60);

    button_sub = gtk_button_new_with_mnemonic("-");
	gtk_grid_attach(GTK_GRID(grid), button_sub, 3, 3, 1, 1);
	gtk_widget_set_size_request(button_sub, 60, 60);

    button_add = gtk_button_new_with_mnemonic("+");
	gtk_grid_attach(GTK_GRID(grid), button_add, 3, 4, 1, 1);
	gtk_widget_set_size_request(button_add, 60, 60);

    button_eq = gtk_button_new_with_mnemonic("=");
	gtk_grid_attach(GTK_GRID(grid), button_eq, 2, 5, 2, 1);
	gtk_widget_set_size_request(button_eq, 60, 60);

    /* N buttons */
    button_dot = gtk_button_new_with_mnemonic(".");
	gtk_grid_attach(GTK_GRID(grid), button_dot, 1, 5, 1, 1);
	gtk_widget_set_size_request(button_dot, 60, 60);
    g_signal_connect(button_dot, "clicked", G_CALLBACK(button_dot_clicked), entry);

    button_1 = gtk_button_new_with_mnemonic("1");
	gtk_grid_attach(GTK_GRID(grid), button_1, 0, 4, 1, 1);
	gtk_widget_set_size_request(button_1, 60, 60);
    g_signal_connect(button_1, "clicked", G_CALLBACK(button_1_clicked), entry);

    button_2 = gtk_button_new_with_mnemonic("2");
	gtk_grid_attach(GTK_GRID(grid), button_2, 1, 4, 1, 1);
	gtk_widget_set_size_request(button_2, 60, 60);
    g_signal_connect(button_2, "clicked", G_CALLBACK(button_2_clicked), entry);

    button_3 = gtk_button_new_with_mnemonic("3");
	gtk_grid_attach(GTK_GRID(grid), button_3, 2, 4, 1, 1);
	gtk_widget_set_size_request(button_3, 60, 60);
    g_signal_connect(button_3, "clicked", G_CALLBACK(button_3_clicked), entry);

    button_4 = gtk_button_new_with_mnemonic("4");
	gtk_grid_attach(GTK_GRID(grid), button_4, 0, 3, 1, 1);
	gtk_widget_set_size_request(button_4, 60, 60);
    g_signal_connect(button_4, "clicked", G_CALLBACK(button_4_clicked), entry);

    button_5 = gtk_button_new_with_mnemonic("5");
	gtk_grid_attach(GTK_GRID(grid), button_5, 1, 3, 1, 1);
	gtk_widget_set_size_request(button_5, 60, 60);
    g_signal_connect(button_5, "clicked", G_CALLBACK(button_5_clicked), entry);

    button_6 = gtk_button_new_with_mnemonic("6");
	gtk_grid_attach(GTK_GRID(grid), button_6, 2, 3, 1, 1);
	gtk_widget_set_size_request(button_6, 60, 60);
    g_signal_connect(button_6, "clicked", G_CALLBACK(button_6_clicked), entry);

    button_7 = gtk_button_new_with_mnemonic("7");
	gtk_grid_attach(GTK_GRID(grid), button_7, 0, 2, 1, 1);
	gtk_widget_set_size_request(button_7, 60, 60);
    g_signal_connect(button_7, "clicked", G_CALLBACK(button_7_clicked), entry);

    button_8 = gtk_button_new_with_mnemonic("8");
	gtk_grid_attach(GTK_GRID(grid), button_8, 1, 2, 1, 1);
	gtk_widget_set_size_request(button_8, 60, 60);
    g_signal_connect(button_8, "clicked", G_CALLBACK(button_8_clicked), entry);

    button_9 = gtk_button_new_with_mnemonic("9");
	gtk_grid_attach(GTK_GRID(grid), button_9, 2, 2, 1, 1);
	gtk_widget_set_size_request(button_9, 60, 60);
    g_signal_connect(button_9, "clicked", G_CALLBACK(button_9_clicked), entry);

    button_0 = gtk_button_new_with_mnemonic("0");
	gtk_grid_attach(GTK_GRID(grid), button_0, 0, 5, 1, 1);
	gtk_widget_set_size_request(button_0, 60, 60);
    g_signal_connect(button_0, "clicked", G_CALLBACK(button_0_clicked), entry);

    gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("edu.lamjiidii1.calculator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
