#ifndef MINESTORM_H
#define MINESTORM_H

class MineStorm
{
public:
    MineStorm();
    /**
     * @brief draw
     * @param painter
     */
    virtual void draw(QPainter &painter);

    /**
     * @brief Appelée lorsqu'une touche est appuyée
     * @param key : touche pressée
     */
    void keyPressed( int key );

    /**
     * @brief Appelée lorsqu'une touche est relâchée
     * @param key : touche relâchée
     */
    void keyReleased( int key );

    /**
     * @brief Permet de générer des mines disposées aléatoirement
     * @param small : Nombre de petites mines
     * @param medium : Nombre de mines moyennes
     * @param big : Nombre de grandes mines
     */
    void generateMines(int small, int medium, int big);

    /**
     * @brief Décrémente le compteur de vie si il en reste, sinon Game Over
     */
    void looseLife();
private :
    /**
     * @brief Initialise le jeu
     */
    void initialize();

    /**
     * @brief Rajoute des mines
     */
    void respawn();

    /**
     * @brief Ajoute une Bullet à l'affichage
     */
    void fire();
    SpaceShip *_ship;

    std::vector<ShipBullet> _bullettab; // !!
    std::vector<Mine> _minetab;
    std::vector<Explosion> _explosiontab;


    bool _leftKeyPressed;
    bool _rightKeyPressed;
    bool _upKeyPressed;
    bool _DownKeyPressed; //Touche de test, à enlever dans la version finale
    bool _spaceKeyPressed;

    int _lifecount;
    int _fireCounter;
    int _accelerationFactor;
    int _respawnCounter;
    int _RespawnCooldown;
};

#endif // MINESTORM_H
