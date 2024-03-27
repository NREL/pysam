import PySAM.Windpower as wind

from .HybridBase import HybridGenerator

class WindHybrid(HybridGenerator):
    """
    Class that adds Windpower to HybridSystem
    """
    def __init__(self) -> None:
        super().__init__(wind, "windpower")
        self._data: wind.Windpower