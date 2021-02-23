#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Point p {700,300};

	int xlabel = 600;
	int ylabel = 400;

	Simple_window win {
		p,xlabel,ylabel,"My label"
	};


	int xorigo = xlabel/2;
	int yorigo = ylabel/2;

	Axis xb {Axis::x, Point{20, yorigo}, xlabel-40, (xlabel-40)/30, "x"};
	Axis yb {Axis::y, Point{xorigo, (ylabel-40) + 20}, ylabel-40, (ylabel-40)/30, "y"};
	xb.set_color(Color::red);
	xb.label.set_color(Color::blue);
	yb.set_color(Color::cyan);
	yb.label.set_color(Color::blue);


	Function sine(sin, 0, 100, Point(50,150), 1000,50,50);
	sine.set_color(Color::yellow);
	sine.set_style(Line_style(Line_style::dot,4));

	Polygon poly;
	poly.add(Point{350,350});
	poly.add(Point{425,250});
	poly.add(Point{500,350});
	poly.set_color(Color::black);
	poly.set_fill_color(Color::red);
	poly.set_style(Line_style(Line_style::dash,4));

	Rectangle r {Point{100,40}, 100, 50};
	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dot,6));
	r.set_color(Color::red);

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,250});
	poly_rect.add(Point{200,250});
	poly_rect.add(Point{200,300});
	poly_rect.add(Point{100,300});
	poly_rect.add(Point{30,275});
	poly_rect.set_fill_color(Color::cyan);

	Text t {Point{325,75}, "Hello graphical world! "};
	t.set_font(Font::courier_bold);
	t.set_font_size(20);

	Image ii {Point{(xlabel/2)/2-50,0},"badge.jpg"};

	Circle c {Point{50,350},40};
	c.set_fill_color(Color::black);
	c.set_style(Line_style(Line_style::dot,3));
	c.set_color(Color::white);
	
	Mark m {Point{50,360},'X'};
	m.set_color(Color::white);

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max() <<
	 "; window size: " << win.x_max() << "*" << win.y_max();

	Text sizes{Point{10,20}, oss.str()};
	sizes.set_color(Color::green);
	sizes.set_font_size(20);
	sizes.set_font(Font::times_bold);

	win.attach(ii);
	win.attach(sizes);
	win.attach(c);
	win.attach(m);
	win.attach(t);
	win.attach(poly_rect);
	win.attach(r);
	win.attach(xb);
	win.attach(yb);
	win.attach(poly);
	win.attach(sine);
	


	win.wait_for_button();

}