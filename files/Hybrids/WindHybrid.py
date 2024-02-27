import PySAM.Windpower as wind

from .HybridBase import HybridGenerator

class WindHybrid(HybridGenerator):
    def __init__(self, hybrid_data, name="windpower") -> None:
        super().__init__(wind, name, hybrid_data)
        self._data: wind.Windpower