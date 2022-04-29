//
//  PianoRay
//  Piano performance visualizer.
//  Copyright  PianoRay Authors  2022
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>

#include "pr_image.hpp"
#include "pr_math.hpp"
#include "pr_piano.hpp"
#include "pr_random.hpp"


namespace Pianoray {


/**
 * Status for a smoke simulation.
 */
class Smoke {
public:
    int width, height;
    double* intensity;
    double* velocity;

    /**
     * Initialize.
     * @param res_x, res_y  Screen resolution.
     * @param subdivs_x  Subdivisions horizontally.
     */
    Smoke(int res_x, int res_y, double subdivs_x) {
        int subx = (int)subdivs_x;
        int suby = (int)(subdivs_x * res_y / res_x);
        int size = subx * suby;

        width = subx;
        height = suby;
        intensity = new double[size];
        velocity = new double[size];
    }

    double get_i(int x, int y) {
        return get(intensity, x, y);
    }

    double get_v(int x, int y) {
        return get(velocity, x, y);
    }

    double set_i(int x, int y, int v) {
        set(intensity, x, y, v);
    }

    double set_v(int x, int y, int v) {
        set(velocity, x, y, v);
    }

    void render(Image& img) {
        double scale_x = (double)img.width / width;
        double scale_y = (double)img.height / height;

        for (int sy = 0; sy < height; sy++) {
            for (int sx = 0; sx < width; sx++) {

            }
        }
    }

private:
    int index(int x, int y) {
        return y*width + x;
    }

    double get(double* array, int x, int y) {
        return array[index(x, y)];
    }

    void set(double* array, int x, int y, double v) {
        array[index(x, y)] = v;
    }
};


/**
 * Render and simulate smoke.
 *
 * @param img_data, width, height  Image parameters.
 * @param frame  Frame to render.
 *
 * @param num_notes  Number of MIDI notes passed in.
 * @param note_keys  Key (note number) for each note.
 * @param note_starts  Start frame of each note.
 * @param note_ends  End frame of each note.
 *
 * @param black_width  settings.piano.black_width_fac
 * @param subdivs  settings.smoke.subdivs
 */
extern "C" void render_smoke(
    UCH* img_data, int width, int height,
    int frame,
    int num_notes, int* note_keys, double* note_starts, double* note_ends,
    double black_width, double subdivs)
{
    Image img(img_data, width, height, 3);
}


}  // namespace Pianoray
