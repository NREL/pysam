import PySAM.Pvsamv1 as pv

from .HybridBase import HybridGenerator

class PVHybrid(HybridGenerator):
    """
    Class that adds Pvsamv1 to HybridSystem
    """
    def __init__(self) -> None:
        super().__init__(pv, "pvsamv1")
        self._data: pv.Pvsamv1