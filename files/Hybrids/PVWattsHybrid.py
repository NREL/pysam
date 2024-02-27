import PySAM.Pvwattsv8 as pvwatts

from .HybridBase import HybridGenerator

class PVWattsHybrid(HybridGenerator):
    def __init__(self, hybrid_data, name="pvwattsv8") -> None:
        super().__init__(pvwatts, name, hybrid_data)
        self._data: pvwatts.Pvwattsv8