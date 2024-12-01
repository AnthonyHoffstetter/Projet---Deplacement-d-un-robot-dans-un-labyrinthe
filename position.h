#ifndef POSITION_H
#define POSITION_H

/**Faire les tests unitaires de cette classe */

class position{
    public:
        position() : d_x(0), d_y(0) {}
        position(int x,int y);
        int getX() const;
        int getY() const;
        void setPosition(int x,int y);
        bool estEgale(const position &p) const;
        bool operator==(const position &p1) const;
        bool operator!=(const position &p1) const;

    private:
        int d_x;
        int d_y;

};

#endif // POSITION_H
