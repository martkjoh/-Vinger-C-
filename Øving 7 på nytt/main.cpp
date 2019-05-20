#include "Emoji.h"
#include "Simple_window.h"
int main()
{
    Graph_lib::Window win(Point{100, 100}, 300*3, 300, "test");
    Vector_ref<Emoji> a;
    a.push_back(new NeutralFace(Point{150, 150}, 100));
    a.push_back(new HappyFace(Point{450, 150}, 100));
    a.push_back(new SadFace(Point{750, 150}, 100));
    for (int i = 0; i < a.size(); i++)
        a[i].attach_to(win);
    return gui_main();
}