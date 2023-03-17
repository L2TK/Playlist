#include "PlaylistNode.h"
#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs("input.txt");

void PrintMenu(string title){
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}
PlaylistNode* ExecuteMenu(char choice, string title, PlaylistNode* headNode){
    PlaylistNode* curr = headNode;
    if(choice == 'o'){
        cout << title << " - OUTPUT FULL PLAYLIST" << endl;
        if(headNode->GetNext() == nullptr){
            cout << "Playlist is empty" << endl;
        }
        else{
            int count = 1;
            curr = curr->GetNext();
            while(curr){
                cout << count << "." << endl;
                curr->PrintPlaylistNode();
                if(curr->GetNext() != nullptr){
                    cout << endl;
                }
                curr = curr->GetNext();
                count++;
            }
        }
    }
    else if(choice == 'a'){
        string id, name, artist;
        int length;
        while(curr->GetNext() != nullptr){ //move curr ptr to the last node
            curr = curr->GetNext();
        }
        
        cout << "ADD SONG" << endl;
        cout << "Enter song\'s unique ID:" << endl;
        ifs.ignore();
        getline(ifs, id);
        cout << "Enter song\'s name:" << endl;
        getline(ifs, name);
        cout << "Enter artist\'s name:" << endl;
        getline(ifs, artist);
        cout << "Enter song\'s length (in seconds):" << endl;
        ifs >> length;

        PlaylistNode* new_node = new PlaylistNode(id, name, artist, length);
        curr->InsertAfter(new_node);
    }
    else if(choice == 'd'){
        string input_id;
        cout << "REMOVE SONG" << endl;
        cout << "Enter song\'s unique ID:" << endl;
        ifs >> input_id;
        
        headNode->RemovePlaylistNode(input_id);
    }
    else if(choice == 'c'){
        string targeted_title;
        int position, new_position;

        cout << "CHANGE POSITION OF SONG" << endl;
        cout << "Enter song\'s current position:" << endl;
        ifs >> position;
        cout << "Enter new position for song:" << endl;
        ifs >> new_position;

        headNode->ChangePosition(position, new_position);
    }
    else if(choice == 's'){
        string input_name;
        
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist\'s name:" << endl;
        ifs.ignore();
        getline(ifs, input_name);
        cout << endl;

        curr = curr->GetNext();

        int counter = 1;
        bool first = true;
        while(curr){
            if(curr->GetArtistName() == input_name && first){
                cout << counter << "." << endl;
                curr->PrintPlaylistNode();
                first = false;
            }
            else if(curr->GetArtistName() == input_name && !first){
                cout << endl;
                cout << counter << "." << endl;
                curr->PrintPlaylistNode();
            }
            counter++; 
            curr = curr->GetNext();
        }
    }
    else if(choice == 't'){
        int total_time = 0;
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
        curr = curr->GetNext();
        while(curr){
            total_time += curr->GetSongLength();
            curr = curr->GetNext();
        }
        cout << "Total time: " << total_time << " seconds" << endl;
    }
    return headNode;
}

int main(){
    string playlist_title;
    char choice;
    PlaylistNode* headNode = new PlaylistNode();
    cout << "Enter playlist's title:" << endl;
    getline(ifs, playlist_title);
    cout << endl;

    while(true){
        PrintMenu(playlist_title);
        cout << "Choose an option:" << endl;
        ifs >> choice;
        if(choice == 'q'){
            break;
        }
        if(choice != 'a' && choice != 'd' && choice != 'c' && choice != 's' && choice != 't' && choice != 'o'){
            continue;
        }
        headNode = ExecuteMenu(choice, playlist_title, headNode);
        cout << endl;
    }
    return 0;
}