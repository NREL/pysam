import PySAM.GenericSystem as gensys

from .HybridBase import HybridGenerator

class GenericSystemHybrid(HybridGenerator):
    def __init__(self, hybrid_data, name="generic_system") -> None:
        super().__init__(gensys, name, hybrid_data)
        self._data : gensys.GenericSystem