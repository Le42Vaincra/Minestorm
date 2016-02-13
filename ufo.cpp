#include "ufo.h"

UFO::UFO(QPoint position, int speed, int direction)
    :_position(position), _direction(direction) {
    setSpeed(speed);
}

QPoint UFO::getPosition() {
    return _position;
}

void UFO::setSpeed(int speed) {
    _speed.setX(speed*sin(_direction*M_PI/180));
    _speed.setY(speed*cos(_direction*M_PI/180));
}

int UFO::getSpeed() {
    return sqrt(_speed.x()*_speed.x()+_speed.y()*_speed.y());
}

void UFO::setDirection(int angle) {
    _direction = angle;
}

int UFO::getDirection(){
    return _direction;
}

void UFO::move(QSize bounds) {
    _position.setX(_position.x()+_speed.x());
    _position.setY(_position.y()+_speed.y());

    if (_position.x() < 0){
        _position.setX(_position.x()+bounds.width());
    }
    else if (_position.x() > bounds.width()) {
        _position.setX(_position.x()-bounds.width());
    }

    if (_position.y() < 0){
        _position.setY(_position.y()+bounds.height());
    }
    else if (_position.y() > bounds.height()) {
        _position.setY(_position.y()-bounds.height());
    }
}

bool UFO::inContact(UFO const &object) const{
    return !(getPolygon().intersected(object.getPolygon()).isEmpty());
}


