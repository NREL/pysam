import PySAM.GenericSystem as gensys

from .HybridBase import HybridGenerator

class GenericSystemHybrid(HybridGenerator):
    """
    Class that adds GenericSystem to HybridSystem
    """
    def __init__(self) -> None:
        super().__init__(gensys, "generic_system")
        self._data : gensys.GenericSystem