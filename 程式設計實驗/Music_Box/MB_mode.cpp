#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>
using namespace std;
class MusicBox
{
private:
    bool powerON;
    bool repetition;
    string music;
public:
    MusicBox(bool p=false, bool r=false, string m=""):powerON(p),repetition(r),music(m){}
    void setPowerON(bool p){ powerON = p; }
    void setRepetition(bool r){ repetition = r; }
    void setMusic(string m){ music = m; }
    bool isPowerON(){ return powerON; }
    bool isRepetition(){ return repetition; }
    string getMusic(){ return music; }
    void play(){
        int tone, duration;
        for (int i=0;i<music.size();i+=2){
            switch(music.at(i)){
          		case 'C': case 'c': tone=440; break;
          		case 'D': case 'd': tone=494; break;
          		case 'E': case 'e': tone=554; break;
          		case 'F': case 'f': tone=587; break;
          		case 'G': case 'g': tone=659; break;
          		case 'A': case 'a': tone=740; break;
          		case 'B': case 'b': tone=830; break;
            }
            switch(music.at(i+1)) {
                case '1': duration=300;  break;
                case '2': duration=500;  break;
                case '3': duration=700;  break;
                case '4': duration=900;  break;
                case '5': duration=1100; break;
            }
        }
        Beep(tone, duration);
        Sleep(100);
    }
};

int main() {
    MusicBox mb;
    mb.setPowerON(true);
    mb.setRepetition(true);
    mb.setMusic("C1D1E1F1G1A1B1");
    while (mb.isPowerON()) {
        mb.play();
        if (!mb.isRepetition()) break;
    }
    return 0; 
}