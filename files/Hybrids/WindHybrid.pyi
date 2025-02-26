from .HybridBase import HybridGenerator

class WindHybrid(HybridGenerator):
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

    class Resource(object):
        def assign(self): 
            pass
    
        def export(self) -> dict:
            pass
    
        def __init__(self, *args, **kwargs): 
            pass


        weibull_k_factor = float
        weibull_reference_height = float
        weibull_wind_speed = float
        wind_resource_data = dict
        wind_resource_distribution = tuple
        wind_resource_filename = str
        wind_resource_model_choice = float


    class Turbine(object):
        def assign(self): 
            pass
    
        def export(self) -> dict:
            pass
    
        def __init__(self, *args, **kwargs): 
            pass

        def calculate_powercurve(self, args):
            pass

        wind_resource_shear = float
        wind_turbine_hub_ht = float
        wind_turbine_max_cp = float
        wind_turbine_powercurve_powerout = tuple
        wind_turbine_powercurve_windspeeds = tuple
        wind_turbine_rotor_diameter = float


    class Farm(object):
        def assign(self): 
            pass
    
        def export(self) -> dict:
            pass
    
        def __init__(self, *args, **kwargs): 
            pass


        max_turbine_override = float
        system_capacity = float
        wind_farm_wake_model = float
        wind_farm_xCoordinates = tuple
        wind_farm_yCoordinates = tuple
        wind_resource_turbulence_coeff = float


    class Losses(object):
        def assign(self): 
            pass
    
        def export(self) -> dict:
            pass
    
        def __init__(self, *args, **kwargs): 
            pass


        avail_bop_loss = float
        avail_grid_loss = float
        avail_turb_loss = float
        elec_eff_loss = float
        elec_parasitic_loss = float
        en_icing_cutoff = float
        en_low_temp_cutoff = float
        env_degrad_loss = float
        env_env_loss = float
        env_exposure_loss = float
        env_icing_loss = float
        icing_cutoff_rh = float
        icing_cutoff_temp = float
        low_temp_cutoff = float
        ops_env_loss = float
        ops_grid_loss = float
        ops_load_loss = float
        ops_strategies_loss = float
        turb_generic_loss = float
        turb_hysteresis_loss = float
        turb_perf_loss = float
        turb_specific_loss = float
        wake_ext_loss = float
        wake_future_loss = float
        wake_int_loss = float


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

    class Uncertainty(object):
        def assign(self): 
            pass
    
        def export(self) -> dict:
            pass
    
        def __init__(self, *args, **kwargs): 
            pass


        total_uncert = float


    class Outputs(object):
        def assign(self): 
            pass
    
        def export(self) -> dict:
            pass
    
        def __init__(self, *args, **kwargs): 
            pass


        annual_energy = float
        annual_energy_distribution_time = tuple
        annual_energy_p75 = float
        annual_energy_p90 = float
        annual_energy_p95 = float
        annual_gross_energy = float
        avail_losses = float
        capacity_factor = float
        cf_battery_replacement_cost_schedule = tuple
        cf_energy_net = tuple
        cf_fuelcell_replacement_cost_schedule = tuple
        cf_om_capacity = tuple
        cf_om_fixed = tuple
        cf_om_fuel_cost = tuple
        cf_om_land_lease = tuple
        cf_om_production = tuple
        cutoff_losses = float
        elec_losses = float
        elev = float
        env_losses = float
        gen = tuple
        kwh_per_kw = float
        lat = float
        lon = float
        monthly_energy = tuple
        ops_losses = float
        pressure = tuple
        temp = tuple
        turb_losses = float
        turbine_output_by_windspeed_bin = tuple
        wake_losses = float
        wind_direction = tuple
        wind_speed = tuple
        wind_speed_average = float
        year = float