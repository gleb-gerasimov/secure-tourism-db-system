## Overview
Desktop application for managing a tourism agency database built with C++, Qt and SQLite.
The application allows users to store, edit and search information about clients, tours and hotels through a graphical user interface.

## Build
```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH="<Qt_path>;<MinGW_path>"
cmake --build build
```

## Screenshots
| Add record | View table | Average cost |
| --- | --- | --- |
|![](/screenshots/screenshot_add_record.png) | ![](/screenshots/screenshot_view_table.png) | ![](/screenshots/screenshot_average_cost.png) |
