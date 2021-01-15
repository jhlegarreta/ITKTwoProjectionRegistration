# -*- coding: utf-8 -*-
from __future__ import print_function
from os import sys

try:
    from skbuild import setup
except ImportError:
    print('scikit-build is required to build from source.', file=sys.stderr)
    print('Please run:', file=sys.stderr)
    print('', file=sys.stderr)
    print('  python -m pip install scikit-build')
    sys.exit(1)

setup(
    name='itk-twoprojectionregistration',
    version='1.1.0',
    author='Jian Wu',
    author_email='jwu2@ufl.edu',
    packages=['itk'],
    package_dir={'itk': 'itk'},
    download_url=r'https://github.com/InsightSoftwareConsortium/ITKTwoProjectionRegistration',
    description=r'ITK classes for two-projection 2D/3D registration',
    long_description='itk-twoprojectionregistration provides an implementation '
                     'of intensity-based 2D/3D rigid image registration for '
                     'patient setup assessment in external beam radiotherapy.\n'
                     'Please refer to:\n'
                     'J. Wu, "ITK-Based Implementation of Two-Projection 2D/3D '
                     'Registration Method with an Application in Patient Setup '
                     'for External Beam Radiotherapy", Insight Journal, '
                     'July-December 2010, http://hdl.handle.net/10380/3245.',
    classifiers=[
        "License :: OSI Approved :: Apache Software License",
        "Programming Language :: Python",
        "Programming Language :: C++",
        "Development Status :: 4 - Beta",
        "Intended Audience :: Developers",
        "Intended Audience :: Education",
        "Intended Audience :: Healthcare Industry",
        "Intended Audience :: Science/Research",
        "Topic :: Scientific/Engineering",
        "Topic :: Scientific/Engineering :: Medical Science Apps.",
        "Topic :: Scientific/Engineering :: Information Analysis",
        "Topic :: Software Development :: Libraries",
        "Operating System :: Android",
        "Operating System :: Microsoft :: Windows",
        "Operating System :: POSIX",
        "Operating System :: Unix",
        "Operating System :: MacOS"
        ],
    license='Apache',
    keywords='ITK InsightToolkit Projection Registration',
    url=r'https://github.com/InsightSoftwareConsortium/ITKTwoProjectionRegistration',
    install_requires=[
        r'itk>=5.2rc1'
    ]
    )
