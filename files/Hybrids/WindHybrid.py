import PySAM.Windpower as wind

from .HybridBase import HybridGenerator

class WindHybrid(HybridGenerator):
    """
    Class that adds Windpower to HybridSystem
    """
    def __init__(self, name="windpower") -> None:
        super().__init__(wind, name)
        self._data: wind.Windpower