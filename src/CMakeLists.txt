add_executable(othello main.cpp game.cpp game_manager.cpp playground.cpp)
target_link_libraries(othello boost_serialization)

add_executable(hra2016cli hra2016-cli.cpp cligame.cpp gameio.cpp climenu.cpp game.cpp game_manager.cpp playground.cpp commandlineinterface.cpp)
target_link_libraries(hra2016cli boost_serialization)

add_executable(test_ test.cpp game.cpp game_manager.cpp playground.cpp)
target_link_libraries(test_ boost_serialization)

#add_subdirectory(boost)
