#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <map>
#include <vector>
#include <string>
#include <game.hpp>

#include <boost/serialization/string.hpp>
#include <boost/serialization/map.hpp>

class GameManager{
    Game *game;
    bool initialized;
    std::map<string, Game*> saved;

    friend class boost::serialization::access;

    template<typename Archive>
    void serialize(Archive& ar, const unsigned version) {
        ar & saved;
        cout << version;
    }
public:
	GameManager();
	~GameManager();

    Game & getGame();

	void initNewGame(string game_name, GameMode mode, int size, string name1, Color color, Difficulty d);
    void initNewGame(string game_name, GameMode mode, int size, string name1, Color color, string name2);

    void saveGame();
    void loadGame(string name);
    void removeGame(string name);

    void serialize(string filename);
    void deserialize(string filename);

    vector<string> * getSavedGames();

};

#endif
