#include "spaceship.h"
#include <QPolygon>

SpaceShip::SpaceShip(QPoint position, int orientation):SpaceShip(position) {
    _orientation = orientation;
    _acceleration = 0;
    _maxspeed = 8;
    this->_invicibleDuration= 80;
}

void SpaceShip::draw(QPainter &painter) {
    QPainterPath path;
    path.addPolygon(this->getPolygon());
    if(this->_invicibleDuration%12 < 8)
        painter.drawPath(path);

    if(this->isInvincible()){
        this->_invicibleDuration--;
    }
}

void SpaceShip::rotateLeft(){
    _orientation += 10;
}

void SpaceShip::rotateRight(){
    _orientation -= 10;
}

void SpaceShip::accelerate() {
    ++_acceleration;

    _speed.setX(_speed.x()+(_acceleration*sin(_orientation*M_PI/180)));
    _speed.setY(_speed.y()+(_acceleration*cos(_orientation*M_PI/180)));

    if (getSpeed() > _maxspeed) {
        setDirection(_orientation);
        setSpeed(_maxspeed);
    }
}

void SpaceShip::stopAcceleration() {
    _acceleration = 0;
}
//Fonction utilisée pour les tests, stoppe le vaisseau
void SpaceShip::stop() {
    _speed.setX(0);
    _speed.setY(0);
}

int SpaceShip::getOrientation() {
    return _orientation;
}

QPoint SpaceShip::getAbsolutePoint(QPoint relativePoint) const {
    QPoint absolutePoint = QPoint(_position.x()+relativePoint.x(), _position.y()+relativePoint.y());
    return QPoint(sin(_orientation*M_PI/180)*(absolutePoint.x()-_position.x()) - cos(_orientation*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.x(),
                  cos(_orientation*M_PI/180)*(absolutePoint.x()-_position.x()) + sin(_orientation*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.y());
}

QPolygon SpaceShip::getPolygon() const{
    QPolygon ship;
    ship.append(getAbsolutePoint(QPoint(0, -10)));
    ship.append(getAbsolutePoint(QPoint(-10, -10)));
    ship.append(getAbsolutePoint(QPoint(0, 0)));
    ship.append(getAbsolutePoint(QPoint(3, 3)));
    ship.append(getAbsolutePoint(QPoint(20, 0)));
    ship.append(getAbsolutePoint(QPoint(3, -3)));
    ship.append(getAbsolutePoint(QPoint(0, 0)));
    ship.append(getAbsolutePoint(QPoint(-10, 10)));
    ship.append(getAbsolutePoint(QPoint(0, 10)));
    return ship;
}

bool SpaceShip::isInvincible(){
    return this-> _invicibleDuration >= 0;
}

void SpaceShip::resetInvincible(){
    this->_invicibleDuration = 72;
}
