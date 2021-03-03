#include "Simple_window.h"
#include "Graph.h"


using namespace Graph_lib;

int main()
{

// 1. feladat

	int xlabel = 800;
	int ylabel = 1000;
	Point p {100,50};

	Simple_window win {
		p, xlabel, ylabel, "13_Drill_label"
	};


// 2.feladat

	Lines grid;
	int x_size = 800;
	int x_grid = 100;

	for(int x = x_grid; x <= x_size; x+= x_grid){

		grid.add(Point{x,0}, Point{x,x_size});
		grid.add(Point{0,x}, Point{x_size,x});
	}

	win.attach(grid);

// 3. feladat

	Vector_ref<Rectangle> rectangles;

    for (int i = 0; i < x_size; i += x_grid) 
    {
        rectangles.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        
        rectangles[rectangles.size() - 1].set_fill_color(Color::red);

        win.attach(rectangles[rectangles.size() - 1]);
    }

// 4. feladat

    Image first {Point{0,300}, "pikachu.gif"};
    Image second {Point{100,600}, "pikachu.gif"};
    Image third {Point{400,200}, "pikachu.gif"};
    win.attach(first);
    win.attach(second);
    win.attach(third);

// 5. feladat
  	Image dog {Point{0,0}, "kutya.jpg"};
  	dog.set_mask(Point{300,200},100,100);
    win.attach(dog);


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) 
        {
            win.wait_for_button();
            if (j<7)
            {
            	dog.move(100, 0);
            }
            else dog.move(-700, 100); 
        }
                
    }

}