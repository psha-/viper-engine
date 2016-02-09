#ifndef COLLIDER_H
#define COLLIDER_H


class Collider
{
    public:
        Collider();
        virtual bool CheckCollision(Collider *) = 0;
        virtual ~Collider();
    protected:
    private:
};

#endif // COLLIDER_H
