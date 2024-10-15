import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QLineEdit, QPushButton
import pyqtgraph as pg
import numpy as np

class GraphWindow(QWidget):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Расчет параметров электромагнитных волн в средах")
        self.layout = QVBoxLayout()

        self.label_x = QLabel("Введите частоту (ГГц):")
        self.input_x = QLineEdit()

        self.label_z = QLabel("Введите ε1 (для первой среды):")
        self.input_z = QLineEdit()

        self.label_t = QLabel("Введите ε2 (для второй среды):")
        self.input_t = QLineEdit()

        self.plot_button = QPushButton("Построить")
        self.plot_button.clicked.connect(self.plot_graph)

        self.graph_widget = pg.PlotWidget()

        self.layout.addWidget(self.label_x)
        self.layout.addWidget(self.input_x)
        self.layout.addWidget(self.label_z)
        self.layout.addWidget(self.input_z)
        self.layout.addWidget(self.label_t)
        self.layout.addWidget(self.input_t)
        self.layout.addWidget(self.plot_button)
        self.layout.addWidget(self.graph_widget)

        self.setLayout(self.layout)

    def plot_graph(self):
        try:
          
            freq = float(self.input_x.text())  
            epsilon1 = float(self.input_z.text())  
            epsilon2 = float(self.input_t.text()) 

            #freq_hz = freq * 1e9

     
            #c = 3e8 
            #mu0 = 4 * np.pi * 1e-7 

   
            #wavelength1 = c / (freq_hz * np.sqrt(epsilon1))
            #wavelength2 = c / (freq_hz * np.sqrt(epsilon2))
            #phase_velocity1 = c / np.sqrt(epsilon1)
            #phase_velocity2 = c / np.sqrt(epsilon2)

      
            #theta_brewster = np.degrees(np.arctan(np.sqrt(epsilon2 / epsilon1)))
            angles = np.linspace(0, 90, 500)

            R_perpendicular = np.abs(
                (np.sqrt(epsilon2) * np.cos(np.radians(angles)) - np.sqrt(epsilon1) * np.cos(np.radians(np.arcsin(np.sqrt(epsilon1 / epsilon2) * np.sin(np.radians(angles)))))) /
                (np.sqrt(epsilon2) * np.cos(np.radians(angles)) + np.sqrt(epsilon1) * np.cos(np.radians(np.arcsin(np.sqrt(epsilon1 / epsilon2) * np.sin(np.radians(angles))))))
            ) ** 2


            R_parallel = np.abs(
                (np.sqrt(epsilon1) * np.cos(np.radians(angles)) - np.sqrt(epsilon2) * np.cos(np.radians(np.arcsin(np.sqrt(epsilon1 / epsilon2) * np.sin(np.radians(angles)))))) /
                (np.sqrt(epsilon1) * np.cos(np.radians(angles)) + np.sqrt(epsilon2) * np.cos(np.radians(np.arcsin(np.sqrt(epsilon1 / epsilon2) * np.sin(np.radians(angles))))))
            ) ** 2

            R_palka = np.abs(
                (np.sqrt(epsilon1) * np.cos(np.radians(angles)) - np.sqrt(epsilon2) * np.cos(np.radians(np.arcsin(np.sqrt(epsilon1 / epsilon2) * np.sin(np.radians(angles)))))) /
                (np.sqrt(epsilon1) * np.cos(np.radians(angles)) + np.sqrt(epsilon2) * np.cos(np.radians(np.arcsin(np.sqrt(epsilon1 / epsilon2) * np.sin(np.radians(angles))))))
            ) ** 2 #узнать че это

            self.graph_widget.clear()

            self.graph_widget.plot(angles, R_perpendicular, pen='r', name="Перпендикулярная поляризация")
            self.graph_widget.plot(angles, R_parallel, pen='b', name="Параллельная поляризация")
            #self.graph_widget.plot(angles, R_palka, pen='g', name="R| поляризация") #это чтобы нарисовать р_палку

        except ValueError:
      
            self.graph_widget.clear()
            self.graph_widget.addItem(pg.TextItem("Введите правильные числовые значения."))


app = QApplication(sys.argv)
window = GraphWindow()
window.show()
sys.exit(app.exec_())
