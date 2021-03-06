#ifndef WINDOW_H
#define WINDOW_H

#include <qwt/qwt_thermo.h>
#include <qwt/qwt_knob.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_dial.h>
#include <qwt/qwt_dial_needle.h>
#include <qwt/qwt_round_scale_draw.h>
#include <qwt/qwt_text_label.h>


#include <QBoxLayout>

#include "audioStreamer.h"

// class definition 'Window'
class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window(); // default constructor - called when a Window is declared without arguments

	~Window();

	void timerEvent( QTimerEvent * );
public slots:
	void setGain(double gain);

// internal variables for the window class
private:
	QwtKnob      *knob;
	QwtThermo    *thermo;
	QwtPlot      *plot;
	QwtPlotCurve *curve;
	QwtDial      *dial;
	QwtPlot      *plot2;
	QwtPlotCurve *curve2;
	QwtTextLabel *currentNoteText; 
	QPainter 	 *dialNoteText;

	QwtDialSimpleNeedle *needle;
 	QwtRoundScaleDraw *roundScale; 


	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QVBoxLayout  *vLayout;  // vertical layout
	QHBoxLayout  *hLayout;  // horizontal layout
	QVBoxLayout  *dialLayout;

	static const int plotDataSize = 512;
	static const int fftPlotDataSize = plotDataSize/2 + 1; 
	// data arrays for the plot
	double xData[plotDataSize];
	double yData[plotDataSize];

	double xData2[plotDataSize];
	double yData2[plotDataSize];

	double gain;
	int count;
	audioStreamer *aStreamer;
};

#endif // WINDOW_H