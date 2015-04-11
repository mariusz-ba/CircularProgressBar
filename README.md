CircularProgressBar
===================

>CircularProgressBar is a simple class which you can use to create circular progress bar in your Qt application

Using CircularProgressBar you can:
- Simple create a circular progress bar
- Easy management using signals and slots
- Change the color you want

There are two options to create a CircularProgressBar object. First and most obvious option is to create a CircularProgressBar object and set its parent widget.
```sh
CircularProgressBar* progressBar = new CircularProgressBar(parentWidget, TYPE);
```
Second option is to create a CircularProgressBar widget as a QWidget object.
```sh
QWidget* progressBar = new CircularProgressBar(parentWidget);
```
If you use second option, in order to access a CircularProgressBar methods, signals or slots, you need to perform a type conversion from QWidget to CircularProgressBar, for example:
```sh
qobject_cast<CircularProgressBar*>(progressBar)->...(any CircularProgressBar method, signal, slot, etc.)
```
