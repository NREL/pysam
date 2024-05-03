# PySAM Windpower Module Example

This example illustrates how to work with PySAM's Windpower module for wind turbines and wind farms.

The Python script reads Windpower model inputs from the `wind-power-inputs.json` file, which was created by exporting inputs from the `windpower-example.sam` file using SAM's Code Generator with the "PySAM JSON" option.

It then loads wind resource data from the `wind-resource-file.csv` file, which is a file from the NREL WIND Toolkit API: https://developer.nrel.gov/docs/wind/wind-toolkit/wtk-download/.

Next it loads a set of wind turbine parameters from the `wind-turbines.json` file that has data for three wind turbines. You can use this file as a model to create your own file of wind turbine parameters.

For the first example, it sets up wind farm coordinates for a single turbine, and then runs a simulation for each of the three turbines.

The second example sets up coordinates for a wind farm with two turbines and reruns the simulations.

The wind farm coordinate inputs `wind_farm_xCoordinates` and `wind_farm_yCoordinates` are relative positions in meters of turbines in the wind farm, where the x-axis is east-west and the y-axis is north-south. For the example with two turbines, Turbine 1 is at (0,0), and Turbine 2 is at (600,0), so the two turbines are spaced 600 meters apart along an east-west axis. During the simulation, the model calculates wake effect losses by taking into account the relative positions of the turbines and the wind direction data in the weather file, along with othe parameters.

To see how the wind farm coordinates work, look at the diagram on SAM's Wind Farm input page. You can use the inputs on that page to design a wind farm layout (see SAM's Help topic for that page for details), and use the code generator to export to JSON and see how SAM's user interface assigns values to the `wind_farm_xCoordinates` and `wind_farm_yCoordinates` inputs. Note that SAM's inputs for Shape, Turbine Spacing, Row Spacing, Offset for rows, etc. are inputs to SAM's user interface but not inputs to the PySAM Windpower module.