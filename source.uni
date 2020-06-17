using olcPixelGameEngine


angle: float(0)
width:int; height:int;

func: bool App::OnUserCreate:
	width = ScreenWidth()
	height = ScreenHeight()
	return true

func: bool App::OnUserUpdate(fElapsedTime: float):

	ca: float = cos(angle + 100)
	cb: float = sin(angle)

	angle += 0.03

	Clear(olc::BLACK)

	w: float = 5
	h: float = (w*height) / width

	xmin: float = -1*w/2
	ymin: float = -1*h/2

	maxIterations: float (100)

	xmax: float = xmin + w
	ymax: float = ymin + h

	dx: float = (xmax - xmin) / width
	dy: float = (ymax - ymin) / height

	x: float = xmin
	for i to width:
		y: float = ymin
		for j to height:
			a: float = x
			b: float = y
			n: float (0)
			while n < maxIterations:
				aa: float = a * a
				bb: float = b * b
				if aa + bb > 4:
					break
				twoab: float = 2 * a * b
				a = aa - bb + ca
				b = twoab + cb
				n <- 1
			pix: olc::Pixel;
			if n == maxIterations:
				pix = olc::Pixel(olc::BLACK)
			else:
				hu: float =  n / maxIterations * 255 + 50
				pix = olc::Pixel(hu*1.2, hu*0.8, hu)
			Draw(i, j, pix)
			y += dy
		x += dx

	return true



func: int main:

	demo: App ("Julia Set")
	if demo.Construct(640, 360, 1, 1):
		demo.Start()

	return 0