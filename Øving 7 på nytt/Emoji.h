#include "Graph_lib.h"
#include "Simple_window.h"

using namespace Graph_lib;

class Emoji
{
    private:
        
    public:
        Emoji(const Emoji&) = delete;
        Emoji() {}
        virtual ~Emoji() {}

        Emoji& operator=(const Emoji&) = delete;

        virtual void attach_to(Graph_lib::Window&) = 0;

};

class Face : public Emoji
{
    private:
        Point center;
        int radius;
        Shape * face;

    public:
        Face(Point center, int radius);

        void attach_to(Graph_lib::Window &win) = 0;
};


class EmptyFace : public Face
{
    private:
        Shape *rEye;
        Shape *lEye;
        int eyeR;

    public:
        EmptyFace(Point center, int radius);
        
        void attach_to(Graph_lib::Window &win) override;
};


class PlainFace  : public EmptyFace
{
    protected:
        Shape *mouth;

    public:
        PlainFace(Point center, int radius);

        void attach_to(Graph_lib::Window &win) override;
};

class HappyFace : public PlainFace
{
    public:
        HappyFace(Point center, int radius) : PlainFace(center, radius)
        {
            mouth = new Arc(Point{center.x, center.y + radius / 3}, radius, radius / 2, 180, 360);
        }
};

class SadFace : public PlainFace
{
    public:
        SadFace(Point center, int radius) : PlainFace(center, radius)
        {
            mouth = new Arc(Point{center.x, center.y + radius / 3}, radius, radius / 2, 180, 0);
        }
};

class NeutralFace : public PlainFace
{
    public:
        NeutralFace(Point center, int radius) : PlainFace(center, radius)
        {
            mouth = new Line(Point{center.x - radius / 2, center.y + radius / 3},
                Point{center.x +radius / 2, center.y + radius/3});
        }
};