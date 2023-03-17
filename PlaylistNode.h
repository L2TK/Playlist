#include <string>
using namespace std;
class PlaylistNode
{
private:
    string id;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
public:
    PlaylistNode();
    PlaylistNode(string id, string songName, string artistName, int songLength);

    void SetNext(PlaylistNode* new_node);
    void InsertAfter(PlaylistNode* new_node);
    void RemovePlaylistNode(string input_id);
    void ChangePosition(int pos, int new_pos);
    void PrintPlaylistNode();


    string GetID(){ return id; }
    string GetSongName(){ return songName; }
    string GetArtistName(){ return artistName; }
    int GetSongLength(){ return songLength; }
    PlaylistNode* GetNext(){ return nextNodePtr; }
    
};

