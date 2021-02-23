#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;


	Point p {400,100};

	int xlabel = x_max() * 2 / 3;
	int ylabel = y_max() * 3 / 4;

	Simple_window win {
		p,xlabel, ylabel, "A man while hacking"
	};

// 1.feladat

	Rectangle r {Point {420,25},150,50};
	r.set_color(Color::blue);
	win.attach(r);

	Polygon poly;
	poly.add(Point{300,75});
	poly.add(Point{350,25});
	poly.add(Point{390,75});
	poly.set_color(Color::red);
	win.attach(poly);

// 2. feladat

	Rectangle rt {Point{100,40}, 100, 30};
	rt.set_color(Color::blue);
	win.attach(rt);

	Text t1 {Point{125,60}, "Howdy!"};
	win.attach(t1);

// 3. feladat

	Text vezeteknev {Point{30,210}, "B"};
	vezeteknev.set_color(Color::yellow);
	vezeteknev.set_font_size(150);
	vezeteknev.set_font(Font::times_bold);
	Text keresztnev {Point{160,210}, "L"};
	keresztnev.set_color(Color::red);
	keresztnev.set_font_size(150);
	keresztnev.set_font(Font::times_bold);

	win.attach(vezeteknev);
	win.attach(keresztnev);

// 4. feladat

Vector_ref<Rectangle> vr;

int kocka = 20;

    for (int oszlop = 0; oszlop < 7; ++oszlop) 
    {
        for (int sor = 0; sor < 7; ++sor)
        {

        	int xpoint = kocka*sor;
        	int ypoint = kocka*oszlop;

            vr.push_back(new Rectangle{Point{100+xpoint, 300+ypoint}, kocka, kocka});

            int i = vr.size()-1;
            if (i % 2 == 0)	
            	vr[i].set_fill_color(Color::red);
            else
            	vr[i].set_fill_color(Color::white);
                
            win.attach(vr[i]);
        }
    }

// 5. feladat

	Rectangle screen {Point{0,0},x_max() * 2 / 3 ,y_max() * 3 / 4};
	screen.set_style(Line_style(Line_style::solid, 8));
	screen.set_color(Color::red);
	win.attach(screen);

// 6. feladat



// 7. feladat

	Rectangle kemeny {Point {970,120},20,60};
	kemeny.set_fill_color(Color::black);
	win.attach(kemeny);
	
	Polygon teto;
	teto.add(Point{950,200});
	teto.add(Point{1025,100});
	teto.add(Point{1100,200});
	teto.set_fill_color(Color::blue);
	win.attach(teto);

	Rectangle haz {Point{950,200},150,150};
	haz.set_fill_color(Color::yellow);
	win.attach(haz);

	
	Rectangle ablak1 {Point{965,230}, 35,35};
	ablak1.set_fill_color(Color::white);
	win.attach(ablak1);
	Rectangle ablak2 {Point{1050,230}, 35,35};
	ablak2.set_fill_color(Color::white);
	win.attach(ablak2);

	Rectangle ajto {Point{1005,290},40,60};
	ajto.set_fill_color(Color::dark_red);
	win.attach(ajto);

	Mark m {Point{1015,325},'.'};
	m.set_color(Color::white);
	win.attach(m);

// 8. feladat

	Circle c1 {Point{600,600},60};
	c1.set_color(Color::black);
	c1.set_style(Line_style(Line_style::solid, 3));
	win.attach(c1);

	Circle c2 {Point{470,600},60};
	c2.set_color(Color::blue);
	c2.set_style(Line_style(Line_style::solid, 3));
	win.attach(c2);

	Circle c3 {Point{730,600},60};
	c3.set_color(Color::red);
	c3.set_style(Line_style(Line_style::solid, 3));
	win.attach(c3);

	Circle c4 {Point{665,670},60};
	c4.set_color(Color::green);
	c4.set_style(Line_style(Line_style::solid, 3));
	win.attach(c4);

	Circle c5 {Point{535,670},60};
	c5.set_color(Color::yellow);
	c5.set_style(Line_style(Line_style::solid, 3));
	win.attach(c5);

// 9. feladat

	Image i {Point{500,150},"ember.jpg"};
	win.attach(i);

	Text szoveg {Point{525, 430}, "A man while hacking"};
    szoveg.set_font_size(20);
    win.attach(szoveg);





	win.wait_for_button();

}