import PySAM.Pvwattsv8 as pvwatts

from .HybridBase import HybridGenerator

class PVWattsHybrid(HybridGenerator):
    """
    Class that adds Pvwattsv8 to HybridSystem
    """
    def __init__(self) -> None:
        super().__init__(pvwatts, "pvwattsv8")
        self._data: pvwatts.Pvwattsv8