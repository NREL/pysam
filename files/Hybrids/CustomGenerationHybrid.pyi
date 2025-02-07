from .HybridBase import HybridGenerator

class CustomGenerationHybrid(HybridGenerator):
    def new(self, str):
        pass

    def default(self, str):
        pass

    def assign(self, dict):
        pass

    def value(self, name, value=None):
        pass

    def unassign(self, name):
        pass

    def execute(self, int_verbosity):
        pass

    def export(self):
        pass

    def __getattribute__(self, *args, **kwargs):
        pass

    def __init__(self, *args, **kwargs):
        pass

    class Plant(object):
        def assign(self): 
            pass
    
        def export(self) -> dict:
            pass
    
        def __init__(self, *args, **kwargs): 
            pass


        conv_eff = float
        derate = float
        energy_output_array = tuple
        heat_rate = float
        spec_mode = float
        system_capacity = float
        user_capacity_factor = float


    class Lifetime(object):
        def assign(self): 
            pass
    
        def export(self) -> dict:
            pass
    
        def __init__(self, *args, **kwargs): 
            pass


        analysis_period = float
        generic_degradation = tuple
        system_use_lifetime_output = float


    class AdjustmentFactors(object):
        def assign(self): 
            pass
    
        def export(self): 
            return {}
    
        def __init__(self, *args, **kwargs): # real signature unknown
            pass
    
        constant = float
        en_hourly = float
        en_periods = float
        en_timeindex = float
        hourly = tuple
        periods = tuple
        imeindex = tuple
        dc_constant = float
        dc_en_hourly = float
        dc_en_periods = float
        dc_en_timeindex = float
        dc_hourly = tuple
        dc_periods = tuple
        dc_imeindex = tuple
        sf_constant = float
        sf_en_hourly = float
        sf_en_periods = float
        sf_en_timeindex = float
        sf_hourly = tuple
        sf_periods = tuple
        sf_timeindex = tuple

    class Outputs(object):
        def assign(self): 
            pass
    
        def export(self) -> dict:
            pass
    
        def __init__(self, *args, **kwargs): 
            pass


        annual_energy = float
        annual_energy_distribution_time = tuple
        annual_fuel_usage = float
        capacity_factor = float
        cf_battery_replacement_cost_schedule = tuple
        cf_energy_net = tuple
        cf_fuelcell_replacement_cost_schedule = tuple
        cf_om_capacity = tuple
        cf_om_fixed = tuple
        cf_om_fuel_cost = tuple
        cf_om_land_lease = tuple
        cf_om_production = tuple
        gen = tuple
        kwh_per_kw = float
        monthly_energy = tuple
        system_heat_rate = float
        water_usage = float