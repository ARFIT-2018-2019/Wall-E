//
// Created by ubuntu on 07/11/18.
//

#ifndef WALL_E_ENUM_DIRECTION_H
#define WALL_E_ENUM_DIRECTION_H
#include <map>

enum class Direction {
    TopRight,
    Top,
    TopLeft,
    Left,
    BotLeft,
    Bot,
    BotRight,
    Right
};

String toString(Direction direction){

    typedef std::map<Direction, String> MapStringDirection;
    typedef std::pair<Direction, String> StringDirection;
    MapStringDirection listDirectionConvert;

    listDirectionConvert.insert(StringDirection(Direction::TopRight, String("TopRight")));
    listDirectionConvert.insert(StringDirection(Direction::Top, String("Top")));
    listDirectionConvert.insert(StringDirection(Direction::TopLeft, String("TopLeft")));
    listDirectionConvert.insert(StringDirection(Direction::Left, String("Left")));
    listDirectionConvert.insert(StringDirection(Direction::BotLeft, String("BotLeft")));
    listDirectionConvert.insert(StringDirection(Direction::Bot, String("Bot")));
    listDirectionConvert.insert(StringDirection(Direction::BotRight, String("BotRight")));
    listDirectionConvert.insert(StringDirection(Direction::Right, String("Right")));

    return listDirectionConvert[direction];
}
#endif //WALL_E_ENUMDIRECTION_H
