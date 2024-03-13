import PySAM.Pvwattsv8 as pvwatts

from .HybridBase import HybridGenerator

class PVWattsHybrid(HybridGenerator):
    def __init__(self, name="pvwattsv8") -> None:
        super().__init__(pvwatts, name)
        self._data: pvwatts.Pvwattsv8