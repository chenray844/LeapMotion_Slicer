# -*- coding:utf-8 -*-

from __main__ import vtk, qt, ctk, slicer

import time
import os
import sys
import multiprocessing
import subprocess

class LeapMotion:
    def __init__(self, parent):
        parent.title = 'LeapMotion'
        parent.categories = ['IGT']
        parent.dependencies = []
        parent.contributors = ['Chen Ruifeng (Cogenda)']
        # print 'dir = ',os.path.dirname(os.path.abspath(__file__))
        # parent.icon = qt.QIcon('/Users/Raymond/Documents/Ray/github_project/LeapMotion_Slicer/resources/leap_motion.png')
        parent.helpText = """
            LeapMotion Module.
        """
        self.parent = parent


# Leap Motion Widget

class LeapMotionWidget:
    def __init__(self, parent=None):
        if not parent:
            self.parent = slicer.qMRMLWidget()
            self.parent.setLayout(qt.QVBoxLayout())
            self.parent.setMRMLScene(slicer.mrmlScene)
        else:
            self.parent = parent

        self.layout = self.parent.layout()

        if not parent:
            self.setup()
            self.parent.show()


    def setup(self):
        leapCollapsibleButton = ctk.ctkCollapsibleButton()
        leapCollapsibleButton.text = 'Leap Motion'
        self.layout.addWidget(leapCollapsibleButton)

        leapFormLayout = qt.QFormLayout(leapCollapsibleButton)

        leapButton = qt.QPushButton('Leap Motion')
        leapButton.setCheckable(True)
        leapButton.connect('clicked(bool)',self.onLeapButtonClicked)
        leapFormLayout.addWidget(leapButton)

        self.layout.addStretch(1)

    def onLeapButtonClicked(self,state):
        pass





