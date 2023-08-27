#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Track {
private:
    std::string title;
    std::time_t recordingDuration;
    std::tm* dateCreation;

public:

    std::string getTitle() {
        return title;
    }
    std::time_t getRecordingDuration() {
        return recordingDuration;
    }
    std::tm* getDateCreation() {
        std::time_t now_time = time(nullptr);
        dateCreation = std::localtime(&now_time);
        return dateCreation;
    }
    std::time_t setRecordingDuration(time_t song_duration) {
        if (song_duration < 0 || (std::isdigit(song_duration))) song_duration = 0;
        return recordingDuration = song_duration;
    }
    std::string setTitle(std::string song_name) {
        return title = song_name;
    }

};

class Player {
private:
    std::vector<Track> track;
    bool isPlay{ false };
    bool isPause{ false };

    void showInfo(Track& track) {
        std::cout << "Track name: " << track.getTitle() << std::endl
            << "Date added to playlist: " << std::asctime(track.getDateCreation())
            << "Play time: " << track.getRecordingDuration() << "second" "\n";
    }

public:
    void play() {
        if (track.empty()) return;
        if (isPause) {
            std::cout << "Pause OFF\n";
            std::cout << "Track playback resumed\n";
            isPause = false;
            isPlay = true;
            return;
        }
        if (!isPlay) {
            std::string titleTrack;
            std::cout << "Enter the title of the track: ";
            std::cin >> titleTrack;
            for (int i = 0; i < track.size(); ++i) {
                if (titleTrack == track[i].getTitle()) {
                    showInfo(track[i]);
                    isPlay = true;
                    return;
                }
            }
            std::cout << "Couldn't find a track with this name\n";
        }
        else std::cout << "The track is already playing!!!\n";
    }

    void addTrack() {
        Track* song = new Track;
        std::cout << "Enter the title new track:";
        std::string song_title;
        std::cin >> song_title;
        std::cout << "Enter recording duration:";
        int song_duration;
        std::cin >> song_duration;
        song->setTitle(song_title);
        song->setRecordingDuration(static_cast<time_t> (song_duration));
        song->getDateCreation();
        track.push_back(*song);
        delete song;
    }

    void pause() {
        if (isPause) play();
        if (isPlay) {
            std::cout << "Pause ON\n";
            isPlay = false;
            isPause = true;
        }
    }

    void next() {
        if (track.empty()) return;
        int randomTrack = std::rand() % track.size();
        showInfo(track[randomTrack]);
        isPlay = true;
    }

    void stop() {
        if (isPlay) std::cout << "Playback is stopped\n";
        isPlay = false;
    }
};

int main() {
    std::cout << "-- Implementing an Audio Player Simulation --" << std::endl;

    Player* player = new Player;
    std::string command;

    do {
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "play") player->play();
        else if (command == "add") player->addTrack();
        else if (command == "pause") player->pause();
        else if (command == "next") player->next();
        else if (command == "stop") player->stop();
        else if (command == "exit") {
            delete player;
            return 0;
        }
        else std::cout << "Command is error! Try again!!!\n";
    } while (true);
}