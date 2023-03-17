#include "PlaylistNode.h"
#include <iostream>
using namespace std;
PlaylistNode::PlaylistNode(){
    id = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}
PlaylistNode::PlaylistNode(string id, string songName, string artistName, int songLength){
    this->id = id;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    nextNodePtr = nullptr;
}

void PlaylistNode::SetNext(PlaylistNode* new_node){
    nextNodePtr = new_node;
}

void PlaylistNode::InsertAfter(PlaylistNode* new_node){
    PlaylistNode* temp = this->nextNodePtr;
    this->nextNodePtr = new_node;
    new_node->nextNodePtr = temp;
}

void PlaylistNode::RemovePlaylistNode(string input_id){
    PlaylistNode* prev = this; //prev = dummy head
    PlaylistNode* curr = this->nextNodePtr; //curr = first node

    while(curr){
        if(curr->id == input_id){
            prev->nextNodePtr = curr->nextNodePtr; //point prev to next node
            cout << "\"" << curr->songName << "\" removed." << endl;
            break;
        }
        prev = curr;
        curr = curr->nextNodePtr;
    }
}

void PlaylistNode::ChangePosition(int pos, int new_pos){
    PlaylistNode* prev;
    PlaylistNode* temp;
    PlaylistNode* curr = this;
    int index = 0;

    //save targeted node & remove & save last node to prev
    while(curr){
        if(index == pos){
            temp = curr;
            prev->nextNodePtr = curr->nextNodePtr; //remove curr node
            //dont break to get the last node in prev
        }
        prev = curr;
        curr = curr->nextNodePtr;
        index++;
    }
    //count size of linked list
    int size = 0;
    curr = this;
    while(curr){
        size++;
        curr = curr->nextNodePtr;
    }

    if(new_pos <= 1){
        this->InsertAfter(temp);
    }
    else if(new_pos >= size){
        prev->InsertAfter(temp); //prev = last node
    }
    else{
        //insert saved node 
        curr = this->nextNodePtr; //reset curr to dummy headNode
        index = 1;
        while(curr){
            if(index == new_pos -1){  //insert temp node after desired index -1
                curr->InsertAfter(temp);
                break;
            }
            index++;
            curr = curr->nextNodePtr;
        }
    }
    cout << "\"" << temp->songName << "\" moved to position " << new_pos << endl;
    
}

void PlaylistNode::PrintPlaylistNode(){
    cout << "Unique ID: " << id << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}