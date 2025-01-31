Settings
========

When creating a video, many settings are passed to PianoRay.
The settings should be stored in a JSON file containing dictionaries
of ``name: value`` pairs with nested dictionaries.

Example
-------

Save a JSON file of your settings, and pass to ``pianoray``.

Example:

.. code-block:: json

    {
        "video": {
            "fps": 30,
            "resolution": [1920, 1080]
        },
        "midi": {
            "path": "/path/to/file.mid"
        }
    }

Available
---------

Most settings have default values. See ``src/utils.py`` for the default
settings.

See devs/info to understand what a "coord" is.

Colors are ``[R, G, B]`` from 0 to 255.

- ``video``: Settings about video export.
    - ``fps``: Frames per second.
    - ``resolution``: Video resolution ``[width, height]``.
    - ``vcodec``: Video codec. This will be passed to FFmpeg, so please
      provide a value that FFmpeg recognizes, e.g. ``libx264``.
- ``audio``: Settings about audio.
    - ``file``: Path to audio file.
    - ``start``: Timestamp, in seconds, you play the first note in the audio.
- ``composition``: Settings about the structure of the video.
    - ``margin_start``: Seconds of video before the first note.
    - ``margin_end``: Seconds of video after the last note ends.
    - ``fade_in``: Seconds of fade in.
    - ``fade_out``: Seconds of fade out.
    - ``fade_blur``: Fade blur radius in coords.
- ``piano``: Settings about the piano.
    - ``black_width_fac``: Black key width as factor of white key width.
- ``blocks``: Settings about blocks.
    - ``speed``: If ``X`` is the distance between the top of the screen and the
      top of the keyboard, the blocks travel ``speed * X`` per second.
    - ``color``: RGB color of the blocks.
    - ``radius``: Block corner rounding radius in coords.
    - ``glow_intensity``: Intensity of glow around the block.
    - ``glow_color``: Color of glow.
    - ``glow_radius``: Radius of glow in coords.
- ``midi``: Settings about MIDI.
    - ``file``: Path to MIDI file.
    - ``speed``: Speed multiplier.
    - ``min_length``: Minimum note length in seconds.
- ``keyboard``: Settings about rendering the keyboard.
    - ``file``: Video file containing recording of playing the keyboard.
    - ``start``: Timestamp, in seconds, you play the first note in the video.
    - ``crop``: Corners of the keyboard in the video, starting from top left and
      going clockwise. Should be ``[[x1, y1], [x2, y2], [x3, y3], [x4, y4]]``.
    - ``dim_mult``: Multiplicative dimming. Give a multiplier value.
    - ``dim_add``: Additive dimming. Subtracted from 0 to 255 channels. If you
      wish to dim, provide a negative value.
    - ``below_length``: Length of the below section in coords.
    - ``octave_lines``: Whether to render octave lines.
- ``glare``: Settings about rendering glare.
    - ``radius``: Radius of glare in coords.
    - ``intensity``: Intensity value.
    - ``jitter``: Random intensity change for each frame.
    - ``streaks``: Number of streaks per glare.
