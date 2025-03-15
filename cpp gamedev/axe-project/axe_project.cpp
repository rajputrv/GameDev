#include "raylib.h"

// the windows origin is at the top left corner ie x,y= 100,150 means 100 pixel to right of left edge, and 150 pixel down of top edge
int main()
{
    // windows dimensions
    int width{800}, height{450};
    InitWindow(width, height, "axe_project");

    // cicle coordinates
    int circle_x{200}, circle_y{200}, circle_radius{25};
    int l_circle_x{circle_x - circle_radius}, r_circle_x{circle_x + circle_radius}; // x cordinate of left, right points of circle
    int u_circle_y{circle_y - circle_radius}, b_circle_y{circle_y + circle_radius}; // y cordinate of upper , bottom points of circle

    // axe coordinates
    int axe_x{400}, axe_y{0}, direction{10}, axe_length{50};
    int l_axe_x{axe_x}, r_axe_x{axe_x + axe_length}, u_axe_y{axe_y}, b_axe_y{axe_y + axe_length};

    bool collision_with_axe =
        (b_axe_y >= u_circle_y) &&
        (u_axe_y <= b_circle_y) &&
        (r_axe_x >= l_circle_x) &&
        (l_axe_x <= r_circle_x);
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("GAME OVER!!!", 400, 200, 20, RED);
        }
        else
        {
            // update edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // update collision axe, or check for if collision happened
            collision_with_axe =
                (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (r_axe_x >= l_circle_x) &&
                (l_axe_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, 50, 50, RED);
            axe_y += direction;
            if (axe_y > height || axe_y < 0)
            {
                direction *= -1;
            }

            if (IsKeyDown(KEY_D) && circle_x < width - circle_radius)
            {
                circle_x += 10;
            }
            else if (IsKeyDown(KEY_A) && circle_x > circle_radius)
            {
                circle_x -= 10;
            }
        }

        EndDrawing();
    }
}