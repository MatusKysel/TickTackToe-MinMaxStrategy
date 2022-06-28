cmake_minimum_required(VERSION 2.8)

project(TicTacToe)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(TICTACTOE_HDRS
	tictactoe.h
    player.h
    ai_player.h
    human_player.h
)

set(TICTACTOE_SRCS
    tictactoe.cc
    ai_player.cc
    human_player.cc
)

add_executable(TicTacToe main.cc ${TICTACTOE_HDRS} ${TICTACTOE_SRCS})
