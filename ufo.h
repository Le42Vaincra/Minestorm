#ifndef UFO_H
#define UFO_H


class UFO
{
public:
    /**
     * @brief Constructeur de UFO
     * @param position : définit la position du UFO dans le jeu
     * @param speed : vitesse du UFO
     * @param direction : sens de déplacement du UFO
     */
    UFO(QPoint position = QPoint(120, 120), int speed = 0, int direction = 0);


    /**
     * @brief Méthode virtuelle pure d'affichage des UFO
     * @param painter : painter servant à peindre le UFO sur l'espace de jeu
     */
    virtual void draw(QPainter &painter) = 0;

    /**
     * @brief Retourne la position actuelle du UFO
     * @return la position sous forme de QPoint
     */
    QPoint getPosition();

    /**
     * @brief Permet de définir la vitesse du UFO
     * @param La nouvelle vitesse du MovableObject
     */
    void setSpeed(int speed);

    /**
     * @brief Retourne la vitesse du UFO
     * @return La vitesse de l'objet
     */
    int getSpeed();


    /**
     * @brief Permet de définir la direction de l'objet
     * @param Angle à appliquer sur le UFO en radian
     */
    void setDirection(int angle);

    /**
     * @brief Retourne la direction que prend actuellement le UFO
     * @return La direction prise
     */
    int getDirection();

    /**
     * @brief Permet de bouger le UFO
     * @param Objet QSize permettant de bouger l'objet
     */
    void move(QSize bounds);

    /**
     * @brief Retourne l'existence d'une intersection entre deux UFO
     * @param Le deuxième UFO
     * @return Vrai s'il existe une intsection, sinon faux
     */
    virtual bool inContact(UFO const &object) const;

    /**
     * @brief Retourne le QPolygon du UFO
     * @return Le QPolygon
     */
    virtual QPolygon getPolygon() const = 0;

protected:
    QPoint _position;
    int _direction;
    QPoint _speed;

private:
};
#endif // UFO_H
