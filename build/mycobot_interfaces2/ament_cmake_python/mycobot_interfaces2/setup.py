from setuptools import find_packages
from setuptools import setup

setup(
    name='mycobot_interfaces2',
    version='0.0.0',
    packages=find_packages(
        include=('mycobot_interfaces2', 'mycobot_interfaces2.*')),
)
