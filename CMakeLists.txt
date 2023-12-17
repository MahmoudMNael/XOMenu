cmake_minimum_required(VERSION 3.26)
project(XOMenu)

set(CMAKE_CXX_STANDARD 17)

add_executable(XOMenu main.cpp
        GameManager.cpp
        Player.cpp
        X_O_Board.cpp
        XOBoardPyramic.cpp
        RandomPlayer.cpp
        GameManger_5x5.cpp
        X_O_Board_5x5.cpp
        X_O_Board_4.cpp
)
