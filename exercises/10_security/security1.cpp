#include <iostream>
#include <string.h>
#include <string>
#include <array>

// security1.cpp
// Make me pass the test! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 


struct Song {
    std::string name_;

    Song() : name_("") {};

    Song(const std::string &name) : name_(name) {};
};

class MediaPlayer {
    static constexpr size_t max_num_songs = 4;
    std::array<Song, max_num_songs> song_ar;
public:
    MediaPlayer() {}

    void set_song(std::string name, int index) {
        song_ar[index] = Song(name);
    }

    std::string get_song_name(int index) const {
        return song_ar[index].name_;
    }
};

const char *convert_to_C_style_string(MediaPlayer &p, int index) {
    int len = p.get_song_name(index).size();
    char *buffer = new char[len+1];
    strncpy(buffer, p.get_song_name(index).c_str(), len+1);
    return buffer;
}

void myprint(const char *str) {
    size_t n = 0;
    do {
        printf("str[%4zu]=", n++);
        switch (*str) {
            case '\0':
                printf("`\\0`\n");
                break;
            case '\n':
                printf("`\\n`\n");
                break;
            case '\r':
                printf("`\\r`\n");
                break;
            case '\b':
                printf("`\\b`\n");
                break;
            case '\t':
                printf("`\\t`\n");
                break;
            case '\v':
                printf("`\\v`\n");
                break;
            default:
                if (*str >= 32 && *str < 128)
                    printf("'%c'\n", *str);
                else
                    printf("'\\x%02hhx\n", *str);
        }
    } while (*str++);
}


#include <catch2/catch.hpp>

TEST_CASE("test_security1_0") {
    MediaPlayer p;
    p.set_song("Old MacDonald had a farm", 0);
    p.set_song("When the circus comes to town", 1);
    REQUIRE(p.get_song_name(0) == "Old MacDonald had a farm");
    const char * second_song = convert_to_C_style_string(p, 0);
    REQUIRE(!strcmp(second_song, "Old MacDonald had a farm"));
}
