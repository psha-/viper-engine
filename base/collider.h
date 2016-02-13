#ifndef COLLIDER_H
#define COLLIDER_H


class Collider
{
    public:
        Collider();
        virtual bool CheckCollision(Collider *);
        virtual ~Collider();
    protected:
    private:
};

#endif // COLLIDER_H
