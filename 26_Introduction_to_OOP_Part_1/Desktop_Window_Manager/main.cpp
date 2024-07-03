#include <iostream>
#include <string>
#include <vector>

class Screen {
public:
    static const int SCREEN_WIDTH = 80;
    static const int SCREEN_HEIGHT = 50;

private:
    std::vector<std::vector<int>> pixels;

public:
    Screen() {
        pixels.resize(SCREEN_HEIGHT, std::vector<int>(SCREEN_WIDTH, 0));
    }

    void display() const {
        for (int row = 0; row < SCREEN_HEIGHT; ++row) {
            for (int col = 0; col < SCREEN_WIDTH; ++col) {
                std::cout << (pixels[row][col] == 1 ? "1" : "0");
            }
            std::cout << std::endl;
        }
    }

    void drawWindow(const class Window& window);

    void clear() {
        pixels.assign(SCREEN_HEIGHT, std::vector<int>(SCREEN_WIDTH, 0));
    }
};

class Window {
private:
    int x;
    int y;
    int width;
    int height;

public:
    Window(int _x = 0, int _y = 0, int _width = 0, int _height = 0)
        : x(_x), y(_y), width(_width), height(_height) {}

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void move(int dx, int dy) {
        if (x + dx >= 0 && x + dx + width <= Screen::SCREEN_WIDTH)
            x += dx;
        else
            std::cout << "Invalid window movement! Window cannot move outside the screen.\n";

        if (y + dy >= 0 && y + dy + height <= Screen::SCREEN_HEIGHT)
            y += dy;
        else
            std::cout << "Invalid window movement! Window cannot move outside the screen.\n";
    }

    void resize(int newWidth, int newHeight) {
        if (newWidth > 0 && x + newWidth <= Screen::SCREEN_WIDTH)
            width = newWidth;
        else
            std::cout << "Invalid window size! Window cannot exceed the screen boundaries.\n";

        if (newHeight > 0 && y + newHeight <= Screen::SCREEN_HEIGHT)
            height = newHeight;
        else
            std::cout << "Invalid window size! Window cannot exceed the screen boundaries.\n";
    }

    void displayInfo() const {
        std::cout << "Window position: (" << x << ", " << y << ")" << std::endl;
        std::cout << "Window size: " << width << "x" << height << std::endl;
    }
};

void Screen::drawWindow(const Window& window) {
    int windowX = window.getX();
    int windowY = window.getY();
    int windowWidth = window.getWidth();
    int windowHeight = window.getHeight();

    if (windowX < 0 || windowX + windowWidth > SCREEN_WIDTH ||
        windowY < 0 || windowY + windowHeight > SCREEN_HEIGHT) {
        std::cout << "Invalid window size! Window cannot be drawn outside the screen.\n";
        return;
    }

    for (int row = windowY; row < windowY + windowHeight; ++row) {
        for (int col = windowX; col < windowX + windowWidth; ++col) {
            pixels[row][col] = 1;
        }
    }
}

int main() {
    std::cout << "-- Desktop Window Manager --\n";

    Screen screen;
    Window mainWindow;

    std::string command;

    while (true) {
        std::cout << "Enter command (move, resize, display, close): ";
        std::cin >> command;

        if (command == "move") {
            int dx, dy;
            std::cout << "Enter movement offset (dx dy): ";
            std::cin >> dx >> dy;
            mainWindow.move(dx, dy);
            mainWindow.displayInfo();
        } else if (command == "resize") {
            int newWidth, newHeight;
            std::cout << "Enter new window dimensions (newWidth newHeight): ";
            std::cin >> newWidth >> newHeight;
            mainWindow.resize(newWidth, newHeight);
            mainWindow.displayInfo();
        } else if (command == "display") {
            screen.clear();
            screen.drawWindow(mainWindow);
            screen.display();
        } else if (command == "close") {
            break;
        } else {
            std::cout << "Command is error! Try again!!!\n";
        }
    }

    return 0;
}
