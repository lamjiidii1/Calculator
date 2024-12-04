#include "calculator.h"
#include "globals.h"
#include "tinyexpr/tinyexpr.h"

static void screen_append(char val){

    if (screen_index<30)
    {
        screen_data[screen_index]=val;
        screen_index++;
    }
    else
    {
        exit(0);
    }
    
}

static void screen_del(){

    if (screen_index<30)
    {   
        screen_data[screen_index-1]='\0';
        screen_index--;
    }
    else
    {
        exit(0);
    }
    
}

void button_del_clicked(GtkButton *button, GtkEntry *entry) {
    if (screen_data[screen_index-1]=='.'){
        is_dot_clicked=false;
        screen_del();
    }
    else
    {
        screen_del();
    }
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_clear_clicked(GtkButton *button, GtkEntry *entry) {
    memset(screen_data, '\0', sizeof(screen_data));
    screen_index=0;
    is_dot_clicked=false;
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_dot_clicked(GtkButton *button, GtkEntry *entry) {
    if (is_dot_clicked==true)
    {
        g_print ("Dot already clicked!\n");
    }
    else
    {
        is_dot_clicked=true;
        if (screen_data[screen_index-1]=='\0' || screen_data[screen_index-1]=='+' || screen_data[screen_index-1]=='-' || screen_data[screen_index-1]=='*' || screen_data[screen_index-1]=='/')
        {
            screen_append('0');
        }
        screen_append('.');
    }
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_add_clicked(GtkButton *button, GtkEntry *entry) {
    if (screen_data[screen_index-1]!='+' && screen_data[screen_index-1]!='-' && screen_data[screen_index-1]!='*' && screen_data[screen_index-1]!='/' && screen_data[screen_index-1]!='\0' && screen_data[screen_index-1]!='.')
    {
        screen_append('+');
        gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
        is_dot_clicked=false;
    }    
}

void button_sub_clicked(GtkButton *button, GtkEntry *entry) {
    if (screen_data[screen_index-1]!='+' && screen_data[screen_index-1]!='-' && screen_data[screen_index-1]!='*' && screen_data[screen_index-1]!='/' && screen_data[screen_index-1]!='\0' && screen_data[screen_index-1]!='.')
    {
        screen_append('-');
        gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
        is_dot_clicked=false;
    }    
}

void button_multi_clicked(GtkButton *button, GtkEntry *entry) {
    if (screen_data[screen_index-1]!='+' && screen_data[screen_index-1]!='-' && screen_data[screen_index-1]!='*' && screen_data[screen_index-1]!='/' && screen_data[screen_index-1]!='\0' && screen_data[screen_index-1]!='.')
    {
        screen_append('*');
        gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
        is_dot_clicked=false;
    }    
}

void button_div_clicked(GtkButton *button, GtkEntry *entry) {
    if (screen_data[screen_index-1]!='+' && screen_data[screen_index-1]!='-' && screen_data[screen_index-1]!='*' && screen_data[screen_index-1]!='/' && screen_data[screen_index-1]!='\0' && screen_data[screen_index-1]!='.')
    {
        screen_append('/');
        gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
        is_dot_clicked=false;
    }    
}

void button_eq_clicked(GtkButton *button, GtkEntry *entry) {

    if (screen_data[screen_index-1]!='+' && screen_data[screen_index-1]!='-' && screen_data[screen_index-1]!='*' && screen_data[screen_index-1]!='/' && screen_data[screen_index-1]!='\0' && screen_data[screen_index-1]!='.')
    {   
        result = te_interp(screen_data, 0);
        if (result)
        {   
            memset(screen_data, '\0', sizeof(screen_data));
            screen_index=0;
            is_dot_clicked=false;
            snprintf(screen_data, sizeof(screen_data), "%.2f", result);
            gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
            memset(screen_data, '\0', sizeof(screen_data));
            screen_index=0;
        }   
    }
    else
    {
        gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
    }
}

void button_0_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('0');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_1_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('1');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_2_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('2');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_3_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('3');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_4_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('4');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_5_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('5');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_6_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('6');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_7_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('7');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_8_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('8');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}

void button_9_clicked(GtkButton *button, GtkEntry *entry) {
    screen_append('9');
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(entry)), screen_data, strlen(screen_data));
}
