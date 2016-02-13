#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "ufo.h"
/**
 * @brief La classe SpaceShip gère le vaisseau
 */
class SpaceShip : public UFO
{
public:
    /**
     * @brief Constructeur
     * @param position : position initiale du vaisseau
     * @param orientation : direction du vaisseau
     */
    SpaceShip(QPoint position, int orientation = 180);
    /**
     * @brief Méthode d'affichage
     * @param painter
     */
    void draw(QPainter &painter);
    /**
     * @brief Tourne dans le sens antihoraire
     */
    void rotateLeft();
    /**
     * @brief Tourne dans le sens horaire
     */
    void rotateRight();
    /**
     * @brief Fait accelerer le vaisseau selon la variable d'accélération
     */
    void accelerate();
    /**
     * @brief Réinitialise la variable d'accélération
     */
    void stopAcceleration();
    /**
     * @brief Renvoie l'orientation du vaisseau
     * @return l'orientation du vaisseau
     */
    int getOrientation();
    /**
     * @brief Stoppe le vaisseau sur place, uniquement en debug mode
     */
    void stop();
    QPolygon getPolygon() const;
    /**
     * @brief Teste l'invicibilité du vaisseau
     * @return true si le vaisseau est en GodMode, false sinon
     */
    bool isInvincible();
    /**
     * @brief Reinitialise la durée du GodMode
     */
    void resetInvincible();
private:
    QPoint getAbsolutePoint(QPoint relativePoint) const;
    int _orientation;
    int _acceleration;
    int _maxspeed;
    int _invicibleDuration;
};

#endif // SPACESHIP_H
