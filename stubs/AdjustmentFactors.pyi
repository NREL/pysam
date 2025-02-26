# encoding: utf-8
# module PySAM.AdjustmentFactors
""" Adjustment Factors for AC, DC and SF adjustments on a constant, hourly, or period basis. """
# no imports

# functions

def new(data_capsule): # real signature unknown; restored from __doc__
    """ new(data_capsule) -> AdjustmentFactors """
    return AdjustmentFactors

# classes

class AdjustmentFactors(object):
    # no doc
    def assign(self): # real signature unknown; restored from __doc__
        """
        assign() -> None
         Assign attributes from dictionary
        """
        pass

    def export(self): # real signature unknown; restored from __doc__
        """
        export() -> Dict
         Export attributes into dictionary
        """
        return {}

    def __init__(self, *args, **kwargs): # real signature unknown
        pass

    adjust_constant = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """AC Constant loss adjustment [%]"""

    adjust_en_hourly = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """Enable AC hourly-based adjustment factors [0/1]"""

    adjust_en_periods = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """Enable AC period-based adjustment factors [0/1]"""

    adjust_en_timeindex = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """Enable AC lfetime adjustment factors [0/1]"""

    adjust_hourly = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """AC Hourly Adjustment Factors [%]"""

    adjust_periods = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """AC Period-based Adjustment Factors [%]"""

    adjust_timeindex = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """AC Lifetime Adjustment Factors [%]"""

    dc_adjust_constant = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """DC Constant loss adjustment [%]"""

    dc_adjust_en_hourly = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """Enable DC hourly-based adjustment factors [0/1]"""

    dc_adjust_en_periods = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """Enable DC period-based adjustment factors [0/1]"""

    dc_adjust_en_timeindex = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """Enable DC lifetime adjustment factors [0/1]"""

    dc_adjust_hourly = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """DC Hourly Adjustment Factors [%]"""

    dc_adjust_periods = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """DC Period-based Adjustment Factors [%]"""

    dc_adjust_timeindex = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """DC Lifetime Adjustment Factors [%]"""

    sf_adjust_constant = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """DC Constant loss adjustment [%]"""

    sf_adjust_en_hourly = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """Enable SF hourly-based adjustment factors [0/1]"""

    sf_adjust_en_periods = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """Enable SF period-based adjustment factors [0/1]"""

    sf_adjust_en_timeindex = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """Enable SF lifetime adjustment factors [0/1]"""

    sf_adjust_hourly = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """DC Hourly Adjustment Factors [%]"""

    sf_adjust_periods = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """DC Period-based Adjustment Factors [%]"""

    sf_adjust_timeindex = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """SF Lifetime Adjustment Factors [%]"""


class error(Exception):
    # no doc
    def __init__(self, *args, **kwargs): # real signature unknown
        pass

    __weakref__ = property(lambda self: object(), lambda self, v: None, lambda self: None)  # default
    """list of weak references to the object (if defined)"""



# variables with complex values

__loader__ = None # (!) real value is '<_frozen_importlib_external.ExtensionFileLoader object at 0x1049b49b0>'

__spec__ = None # (!) real value is "ModuleSpec(name='PySAM.AdjustmentFactors', loader=<_frozen_importlib_external.ExtensionFileLoader object at 0x1049b49b0>, origin='/Users/dguittet/SAM-Dev/PySAM/venv/lib/python3.7/site-packages/NREL_PySAM-1.2-py3.7-macosx-10.14-x86_64.egg/PySAM/AdjustmentFactors.cpython-37m-darwin.so')"

